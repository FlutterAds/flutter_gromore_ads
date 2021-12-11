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
}
- (void)splashAd:(ABUSplashAd *)splashAd didFailWithError:(NSError *)error{
    NSLog(@"%s-error:%@", __func__, error);
}

- (void)splashAdWillVisible:(ABUSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
}

- (void)splashAdDidClick:(ABUSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
}

- (void)splashAdDidClose:(ABUSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
}

@end
