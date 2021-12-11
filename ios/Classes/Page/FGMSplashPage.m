//
//  FGMSplashPage.m
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/11.
//

#import "FGMSplashPage.h"

@interface FGMSplashPage ()<ABUSplashAdDelegate>

@end

@implementation FGMSplashPage

- (void)loadAd:(FlutterMethodCall *)call{
    NSLog(@"%s",__FUNCTION__);
    self.ad =[[ABUSplashAd alloc] initWithAdUnitID:self.posId];
    self.ad.delegate=self;
    self.ad.rootViewController=self.rootController;
    [self.ad loadAdData];
}

- (void)splashAdDidLoad:(ABUSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    [self.ad showInWindow:self.mainWin];
    // 发送事件
    [self sendEventAction:onAdLoaded];
}
- (void)splashAd:(ABUSplashAd *)splashAd didFailWithError:(NSError *)error{
    NSLog(@"%s-error:%@", __func__, error);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)splashAdWillVisible:(ABUSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdExposure];
}

- (void)splashAdDidShowFailed:(ABUSplashAd *)splashAd error:(NSError *)error{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendErrorEvent:error];
}

- (void)splashAdDidClick:(ABUSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdClicked];
}

- (void)splashAdDidClose:(ABUSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdClosed];
}

- (void)splashAdCountdownToZero:(ABUSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdComplete];
}

@end
