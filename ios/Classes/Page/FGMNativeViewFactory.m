//
//  FGMNativeViewFactory.m
//  flutter_gromore_ads
//
//  Created by Zero on 2023/1/12.
//

#import "FGMNativeViewFactory.h"
//#import "FGMAdBannerView.h"
//#import "FGMAdFeedView.h"

@implementation FGMNativeViewFactory


- (instancetype)initWithViewName:(NSString *)viewName withMessenger:(NSObject<FlutterBinaryMessenger> *)messenger withPlugin:(FlutterGromoreAdsPlugin *)plugin{
    self = [super init];
    if (self) {
        self.viewName = viewName;
        self.messenger = messenger;
        self.plugin = plugin;
    }
    return self;
}

- (NSObject<FlutterMessageCodec>*)createArgsCodec {
    return [FlutterStandardMessageCodec sharedInstance];
}

- (NSObject<FlutterPlatformView>*)createWithFrame:(CGRect)frame
                                   viewIdentifier:(int64_t)viewId
                                        arguments:(id _Nullable)args {
//    if (self.viewName==kGMAdBannerViewId) {
//        return [[FGMAdBannerView alloc] initWithFrame:frame
//                                    viewIdentifier:viewId
//                                         arguments:args
//                                   binaryMessenger:self.messenger
//                                            plugin:self.plugin];
//    }else if (self.viewName==kGMAdFeedViewId) {
//        return [[FGMAdFeedView alloc] initWithFrame:frame
//                                    viewIdentifier:viewId
//                                         arguments:args
//                                   binaryMessenger:self.messenger
//                                            plugin:self.plugin];
//    }
    return nil;
}

@end
