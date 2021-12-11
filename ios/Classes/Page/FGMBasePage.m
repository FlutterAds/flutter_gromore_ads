//
//  FGMBasePage.m
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/11.
//

#import "FGMBasePage.h"

@implementation FGMBasePage
- (void)showAd:(FlutterMethodCall *)call eventSink:(FlutterEventSink)events{
    self.posId=call.arguments[@"posId"];
    // 获取控制器
    self.mainWin=[[UIApplication sharedApplication] keyWindow];
    self.rootController=[self.mainWin rootViewController];
    //加载广告
    [self loadAd:call];
}

- (void)loadAd:(FlutterMethodCall *)call{
    NSLog(@"%s",__FUNCTION__);
    
}
@end
