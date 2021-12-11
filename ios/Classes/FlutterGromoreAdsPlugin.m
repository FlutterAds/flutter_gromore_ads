#import "FlutterGromoreAdsPlugin.h"
# if __has_include(<ABUAdSDK/ABUAdSDK.h>)
#import <ABUAdSDK/ABUAdSDK.h>
#else
#import <Ads-Mediation-CN/ABUAdSDK.h>
#endif

@implementation FlutterGromoreAdsPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  FlutterMethodChannel* channel = [FlutterMethodChannel
      methodChannelWithName:@"flutter_gromore_ads"
            binaryMessenger:[registrar messenger]];
  FlutterGromoreAdsPlugin* instance = [[FlutterGromoreAdsPlugin alloc] init];
  [registrar addMethodCallDelegate:instance channel:channel];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
  if ([@"getPlatformVersion" isEqualToString:call.method]) {
    result([@"iOS " stringByAppendingString:[[UIDevice currentDevice] systemVersion]]);
      [ABUAdSDKManager setupSDKWithAppId:@"" config:^ABUUserConfig *(ABUUserConfig *c) {
          c.logEnable = YES;
          return c;
      }];
  } else {
    result(FlutterMethodNotImplemented);
  }
}

@end
