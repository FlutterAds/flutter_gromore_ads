//
//  FGMAdFeedView.h
//  flutter_gromore_ads
//
//  Created by Zero on 2023/2/3.
//

#import "FGMBasePage.h"
#import "FGMFeedAdManager.h"
#import "FlutterGromoreAdsPlugin.h"

@interface FGMAdFeedView : FGMBasePage<FlutterPlatformView>
@property (strong,nonatomic,nullable) FlutterGromoreAdsPlugin *plugin;
@property int64_t viewId;

- (nonnull instancetype)initWithFrame:(CGRect)frame
                       viewIdentifier:(int64_t)viewId
                            arguments:(id _Nullable)args
                      binaryMessenger:(NSObject<FlutterBinaryMessenger>* _Nullable)messenger plugin:(FlutterGromoreAdsPlugin* _Nullable) plugin;

- (nonnull UIView*)view;
@end
