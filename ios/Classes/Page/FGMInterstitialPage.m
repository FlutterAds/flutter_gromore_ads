//
//  FGMInterstitialPage.m
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/12.
//

#import "FGMInterstitialPage.h"

@interface FGMInterstitialPage()<ABUInterstitialAdDelegate>

@end

@implementation FGMInterstitialPage

- (void)loadAd:(FlutterMethodCall *)call{
    int width=[call.arguments[@"width"] intValue];
    int height=[call.arguments[@"height"] intValue];
    self.ad= [[ABUInterstitialAd alloc] initWithAdUnitID:self.posId size:CGSizeMake(width, height)];
    self.ad.delegate=self;
    self.ad.mutedIfCan=YES;
    [self.ad loadAdData];
}

- (void)interstitialAdDidLoad:(ABUInterstitialAd *)interstitialAd{
    NSLog(@"%s",__FUNCTION__);
    if(self.ad && self.ad.isReady){
        [self.ad showAdFromRootViewController:self.rootController];
    }
    // 发送事件
    [self sendEventAction:onAdLoaded];
}

- (void)interstitialAd:(ABUInterstitialAd *)interstitialAd didFailWithError:(NSError *)error{
    NSLog(@"%s-error:%@", __FUNCTION__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)interstitialAdDidVisible:(ABUInterstitialAd *)interstitialAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdExposure];
}

- (void)interstitialAdDidShowFailed:(ABUInterstitialAd *)interstitialAd error:(NSError *)error{
    NSLog(@"%s-error:%@", __FUNCTION__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)interstitialAdViewRenderFail:(ABUInterstitialAd *)interstitialAd error:(NSError *)error{
    NSLog(@"%s-error:%@", __FUNCTION__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)interstitialAdDidClick:(ABUInterstitialAd *)interstitialAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdClicked];
}

- (void)interstitialAdDidClose:(ABUInterstitialAd *)interstitialAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdClosed];
}

@end
