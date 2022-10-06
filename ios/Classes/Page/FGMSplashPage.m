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
    self.isDisplay=YES;
    NSString* logo=call.arguments[@"logo"];
    double timeout=[call.arguments[@"timeout"] doubleValue];
    int buttonType=[call.arguments[@"buttonType"] intValue];
    // logo 判断为空，则全屏展示
    self.fullScreenAd=[logo isKindOfClass:[NSNull class]]||[logo length]==0;
    // 创建广告
    self.ad =[[ABUSplashAd alloc] initWithAdUnitID:self.posId];
    self.ad.delegate=self;
    self.ad.tolerateTimeout=timeout;
    self.ad.splashButtonType=buttonType;
    self.ad.rootViewController=self.rootController;
    if (!self.fullScreenAd) {
        // 设置底部 logo
        self.bottomView=nil;
        CGSize size=[[UIScreen mainScreen] bounds].size;
        CGFloat width=size.width;
        CGFloat height=112.5;// 这里按照 15% 进行logo 的展示，防止尺寸不够的问题，750*15%=112.5
        self.bottomView=[[UIView alloc]initWithFrame:CGRectMake(0, 0,width, height)];
        self.bottomView.backgroundColor=[UIColor whiteColor];
        UIImageView *logoView=[[UIImageView alloc]initWithImage:[UIImage imageNamed:logo]];
        logoView.frame=CGRectMake(0, 0, width, height);
        logoView.contentMode=UIViewContentModeCenter;
        logoView.center=self.bottomView.center;
        [self.bottomView addSubview:logoView];
        [self.ad setCustomBottomView:self.bottomView];
    }
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
    self.isDisplay=NO;
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
    self.isDisplay=NO;
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
    // 销毁广告
    if (self.ad) {
        [self.ad destoryAd];
    }
    self.isDisplay=NO;
}

- (void)splashAdCountdownToZero:(ABUSplashAd *)splashAd{
    NSLog(@"%s",__FUNCTION__);
    // 发送事件
    [self sendEventAction:onAdComplete];
}

@end
