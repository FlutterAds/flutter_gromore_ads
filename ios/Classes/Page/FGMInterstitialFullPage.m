//
//  FGMInterstitialFullPage.m
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/12.
//

#import "FGMInterstitialFullPage.h"

@interface FGMInterstitialFullPage()<ABUInterstitialProAdDelegate>

@end

@implementation FGMInterstitialFullPage

- (void)loadAd:(FlutterMethodCall *)call{
    int width=[call.arguments[@"width"] intValue];
    int height=[call.arguments[@"height"] intValue];
    self.ad =[[ABUInterstitialProAd alloc] initWithAdUnitID:self.posId sizeForInterstitial:CGSizeMake(width, height)];
    self.ad.delegate=self;
    self.ad.mutedIfCan=YES;
    [self.ad loadAdData];
}

- (void)interstitialProAdDidLoad:(ABUInterstitialProAd *)interstitialProAd{
    NSLog(@"%s",__FUNCTION__);
    if(self.ad && self.ad.isReady){
        [self.ad showAdFromRootViewController:self.rootController extroInfos:nil];
    }
    // 发送事件
    [self sendEventAction:onAdLoaded];
}

- (void)interstitialProAd:(ABUInterstitialProAd *)interstitialAd didFailWithError:(NSError *)error{
    NSLog(@"%s-error:%@", __FUNCTION__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)interstitialProAdDidVisible:(ABUInterstitialProAd *)interstitialAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdExposure];
}

- (void)interstitialProAdDidShowFailed:(ABUInterstitialProAd *)interstitialAd error:(NSError *)error{
    NSLog(@"%s-error:%@", __FUNCTION__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)interstitialProAdViewRenderFail:(ABUInterstitialProAd *)interstitialAd error:(NSError *)error{
    NSLog(@"%s-error:%@", __FUNCTION__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)interstitialProAdDidClick:(ABUInterstitialProAd *)interstitialAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdClicked];
}

- (void)interstitialProAdDidClose:(ABUInterstitialProAd *)interstitialAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdClosed];
}


@end
