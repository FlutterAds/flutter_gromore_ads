//
//  FGMAdBannerView.h
//  flutter_gromore_ads
//
//  Created by Zero on 2023/1/12.
//

#import "FGMBasePage.h"
#import "FlutterGromoreAdsPlugin.h"

@interface FGMAdBannerView : FGMBasePage<FlutterPlatformView>
@property (strong,nonatomic,nullable) FlutterGromoreAdsPlugin *plugin;
- (nonnull instancetype)initWithFrame:(CGRect)frame
                       viewIdentifier:(int64_t)viewId
                            arguments:(id _Nullable)args
                      binaryMessenger:(NSObject<FlutterBinaryMessenger>* _Nullable)messenger plugin:(FlutterGromoreAdsPlugin* _Nullable) plugin;

- (nonnull UIView*)view;
@end
