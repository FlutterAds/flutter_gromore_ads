//
//  FGMFullVideoPage.m
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/12.
//

#import "FGMFullVideoPage.h"

@interface FGMFullVideoPage()<ABUFullscreenVideoAdDelegate>

@end

@implementation FGMFullVideoPage

- (void)loadAd:(FlutterMethodCall *)call{
    self.ad=[[ABUFullscreenVideoAd alloc] initWithAdUnitID:self.posId];
    self.ad.delegate=self;
    self.ad.mutedIfCan=YES;
    [self.ad loadAdData];
}


- (void)fullscreenVideoAdDidLoad:(ABUFullscreenVideoAd *)fullscreenVideoAd{
    NSLog(@"%s",__FUNCTION__);
    if(self.ad && self.ad.isReady){
        [self.ad showAdFromRootViewController:self.rootController];
    }
    // 发送事件
    [self sendEventAction:onAdLoaded];
}

- (void)fullscreenVideoAd:(ABUFullscreenVideoAd *)fullscreenVideoAd didFailWithError:(NSError *)error{
    NSLog(@"%s-error:%@", __FUNCTION__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)fullscreenVideoAdDidVisible:(ABUFullscreenVideoAd *)fullscreenVideoAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdExposure];
}

- (void)fullscreenVideoAdDidShowFailed:(ABUFullscreenVideoAd *)fullscreenVideoAd error:(NSError *)error{
    NSLog(@"%s-error:%@", __FUNCTION__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)fullscreenVideoAd:(ABUFullscreenVideoAd *)fullscreenVideoAd didPlayFinishWithError:(NSError *)error{
    NSLog(@"%s-error:%@", __FUNCTION__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)fullscreenVideoAdDidSkip:(ABUFullscreenVideoAd *)fullscreenVideoAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdSkip];
}

- (void)fullscreenVideoAdDidClick:(ABUFullscreenVideoAd *)fullscreenVideoAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdClicked];
}

- (void)fullscreenVideoAdDidClose:(ABUFullscreenVideoAd *)fullscreenVideoAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdClosed];
}

@end
