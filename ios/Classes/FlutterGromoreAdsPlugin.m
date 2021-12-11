#import "FlutterGromoreAdsPlugin.h"
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>
# if __has_include(<ABUAdSDK/ABUAdSDK.h>)
#import <ABUAdSDK/ABUAdSDK.h>
#else
#import <Ads-Mediation-CN/ABUAdSDK.h>
#endif

@implementation FlutterGromoreAdsPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    FlutterMethodChannel* methodChannel = [FlutterMethodChannel
                                     methodChannelWithName:@"flutter_gromore_ads"
                                     binaryMessenger:[registrar messenger]];
    
    FlutterEventChannel* eventChannel=[FlutterEventChannel eventChannelWithName:@"flutter_gromore_ads_event" binaryMessenger:[registrar messenger]];
    
    FlutterGromoreAdsPlugin* instance = [[FlutterGromoreAdsPlugin alloc] init];
    [registrar addMethodCallDelegate:instance channel:methodChannel];
    [eventChannel setStreamHandler:instance];
    
    
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    NSString *methodStr=call.method;
    if ([@"getPlatformVersion" isEqualToString:methodStr]) {
        result([@"iOS " stringByAppendingString:[[UIDevice currentDevice] systemVersion]]);
    }else if ([@"requestIDFA" isEqualToString:methodStr]) {
        [self requestIDFA:call result:result];
    }else if ([@"initAd" isEqualToString:methodStr]){
        [self initAd:call result:result];
    } else {
        result(FlutterMethodNotImplemented);
    }
}

// 请求 IDFA
- (void) requestIDFA:(FlutterMethodCall*) call result:(FlutterResult) result{
    if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            BOOL requestResult=status == ATTrackingManagerAuthorizationStatusAuthorized;
            NSLog(@"requestIDFA:%@",requestResult?@"YES":@"NO");
            result(@(requestResult));
        }];
    } else {
        result(@(YES));
    }
}

// 初始化广告
- (void) initAd:(FlutterMethodCall*) call result:(FlutterResult) result{
    NSString *appId=call.arguments[@"appId"];
    [ABUAdSDKManager setupSDKWithAppId:appId config:^ABUUserConfig *(ABUUserConfig *c) {
        c.logEnable = YES;
        return c;
    }];
    result(@(YES));
}

#pragma mark - FlutterStreamHandler

- (FlutterError *)onCancelWithArguments:(id)arguments{
    self.eventSink = nil;
    return nil;
}
- (FlutterError *)onListenWithArguments:(id)arguments eventSink:(FlutterEventSink)events{
    self.eventSink = events;
    return nil;
}

- (void) addEvent:(NSObject *) event{
    if(self.eventSink){
        self.eventSink(event);
    }
}

@end
