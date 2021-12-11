#import <Flutter/Flutter.h>
#import "FGMSplashPage.h"

@interface FlutterGromoreAdsPlugin : NSObject<FlutterPlugin,FlutterStreamHandler>
@property (strong,nonatomic) FlutterEventSink eventSink;
@property (strong,nonatomic) FGMSplashPage *sad;// 开屏广告

@end
