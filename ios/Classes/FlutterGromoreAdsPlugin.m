#import "FlutterGromoreAdsPlugin.h"
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>
#import "FGMGroMore.h"
#import "FGMNativeViewFactory.h"

@implementation FlutterGromoreAdsPlugin
// AdBannerView
NSString *const kGMAdBannerViewId=@"flutter_gromore_ads_banner";

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    FlutterMethodChannel* methodChannel = [FlutterMethodChannel
                                     methodChannelWithName:@"flutter_gromore_ads"
                                     binaryMessenger:[registrar messenger]];
    
    FlutterEventChannel* eventChannel=[FlutterEventChannel eventChannelWithName:@"flutter_gromore_ads_event" binaryMessenger:[registrar messenger]];
    
    FlutterGromoreAdsPlugin* instance = [[FlutterGromoreAdsPlugin alloc] init];
    [registrar addMethodCallDelegate:instance channel:methodChannel];
    [eventChannel setStreamHandler:instance];

    // 注册平台View 工厂
    FGMNativeViewFactory *bannerFactory=[[FGMNativeViewFactory alloc] initWithViewName:kGMAdBannerViewId withMessenger:registrar.messenger withPlugin:instance];
    // 注册 Banner View
    [registrar registerViewFactory:bannerFactory withId:kGMAdBannerViewId];

    
}
- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    NSString *methodStr=call.method;
    if ([@"getPlatformVersion" isEqualToString:methodStr]) {
        result([@"iOS " stringByAppendingString:[[UIDevice currentDevice] systemVersion]]);
    }else if ([@"requestIDFA" isEqualToString:methodStr]) {
        [self requestIDFA:call result:result];
    }else if ([@"initAd" isEqualToString:methodStr]){
        [self initAd:call result:result];
    }else if ([@"showSplashAd" isEqualToString:methodStr]) {
        [self showSplashAd:call result:result];
    }else if ([@"showInterstitialAd" isEqualToString:methodStr]) {
        [self showInterstitialAd:call result:result];
    }else if ([@"showInterstitialFullAd" isEqualToString:methodStr]) {
        [self showInterstitialFullAd:call result:result];
    }else if ([@"showFullVideoAd" isEqualToString:methodStr]) {
        [self showFullVideoAd:call result:result];
    }else {
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
    NSString *config=call.arguments[@"config"];
    [ABUAdSDKManager setupSDKWithAppId:appId config:^ABUUserConfig *(ABUUserConfig *c) {
        #ifdef DEBUG
            c.logEnable = YES;
        #endif
        // 导入本地配置
        if (![config isKindOfClass:[NSNull class]] && [config length]!=0) {
            c.advanceSDKConfigPath = [[NSBundle mainBundle] pathForResource:config ofType:@"json"];//支持媒体本地提前导入配置信息
        }
        return c;
    }];
    result(@(YES));
}

// 开屏广告
- (void) showSplashAd:(FlutterMethodCall*) call result:(FlutterResult) result{
    if (self.sad!=nil&&self.sad.isDisplay) {
        result(@(NO));
        return;
    }
    self.sad=[[FGMSplashPage alloc] init];
    [self.sad showAd:call eventSink:self.eventSink];
    result(@(YES));
}

// 插屏广告
- (void) showInterstitialAd:(FlutterMethodCall *)call result:(FlutterResult) result{
    self.iad=[[FGMInterstitialPage alloc] init];
    [self.iad showAd:call eventSink:self.eventSink];
    result(@(YES));
}

// 插屏全屏广告
- (void) showInterstitialFullAd:(FlutterMethodCall *)call result:(FlutterResult) result{
    self.ifad=[[FGMInterstitialFullPage alloc] init];
    [self.ifad showAd:call eventSink:self.eventSink];
    result(@(YES));
}

// 全屏视频广告
- (void) showFullVideoAd:(FlutterMethodCall *) call result:(FlutterResult) result{
    self.fvad=[[FGMFullVideoPage alloc] init];
    [self.fvad showAd:call eventSink:self.eventSink];
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
