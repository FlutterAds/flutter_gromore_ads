#import <Flutter/Flutter.h>
#import "FGMSplashPage.h"
#import "FGMInterstitialPage.h"

@interface FlutterGromoreAdsPlugin : NSObject<FlutterPlugin,FlutterStreamHandler>
@property (strong,nonatomic) FlutterEventSink eventSink;// 事件
@property (strong,nonatomic) FGMSplashPage *sad;// 开屏广告
@property (strong,nonatomic) FGMInterstitialPage *iad;// 插屏广告

extern NSString *const kGMAdBannerViewId;
@end
