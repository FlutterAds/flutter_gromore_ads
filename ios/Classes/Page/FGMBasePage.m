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
    self.eventSink=events;
    // 获取控制器
    self.mainWin=[[UIApplication sharedApplication] keyWindow];
    self.rootController=[self.mainWin rootViewController];
    //加载广告
    [self loadAd:call];
}

- (void)loadAd:(FlutterMethodCall *)call{
    NSLog(@"%s",__FUNCTION__);
    
}

- (void)sendEvent:(FGMAdEvent *)event{
    if(self.eventSink){
        self.eventSink(event.toMap);
    }
}

- (void)sendEventAction:(NSString *)action{
    FGMAdEvent *event=[[FGMAdEvent alloc] initWithAdId:self.posId action:action];
    [self sendEvent:event];

}

- (void)sendErrorEvent:(NSError *)error{
    if (self.eventSink) {
        FGMAdErrorEvent *event=[[FGMAdErrorEvent alloc] initWithAdId:self.posId error:error];
        self.eventSink(event.toMap);
    }
}
@end
