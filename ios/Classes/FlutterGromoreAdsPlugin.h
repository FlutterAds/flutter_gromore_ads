#import <Flutter/Flutter.h>

@interface FlutterGromoreAdsPlugin : NSObject<FlutterPlugin,FlutterStreamHandler>
@property (strong,nonatomic) FlutterEventSink eventSink;
@end
