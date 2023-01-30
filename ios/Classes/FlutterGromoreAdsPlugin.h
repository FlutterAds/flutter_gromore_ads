#import <Flutter/Flutter.h>
#import "FGMSplashPage.h"
#import "FGMInterstitialPage.h"
#import "FGMInterstitialFullPage.h"
#import "FGMFullVideoPage.h"

@interface FlutterGromoreAdsPlugin : NSObject<FlutterPlugin,FlutterStreamHandler>
@property (strong,nonatomic) FlutterEventSink eventSink;// 事件
@property (strong,nonatomic) FGMSplashPage *sad;// 开屏广告
@property (strong,nonatomic) FGMInterstitialPage *iad;// 插屏广告
@property (strong,nonatomic) FGMInterstitialFullPage *ifad;//插屏全屏广告
@property (strong,nonatomic) FGMFullVideoPage *fvad;// 全屏视频广告

extern NSString *const kGMAdBannerViewId;
@end
