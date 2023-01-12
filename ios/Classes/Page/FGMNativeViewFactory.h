//
//  FGMNativeViewFactory.h
//  flutter_gromore_ads
//
//  Created by Zero on 2023/1/12.
//

#import <Flutter/Flutter.h>
#import <Foundation/Foundation.h>
#import "FlutterGromoreAdsPlugin.h"

NS_ASSUME_NONNULL_BEGIN

@interface FGMNativeViewFactory : NSObject<FlutterPlatformViewFactory>
@property (strong,nonatomic) NSObject<FlutterBinaryMessenger> *messenger;
@property (strong,nonatomic) FlutterGromoreAdsPlugin *plugin;
@property (strong,nonatomic) NSString *viewName;
- (instancetype)initWithViewName:(NSString*) viewName withMessenger:(NSObject<FlutterBinaryMessenger>*)messenger withPlugin:(FlutterGromoreAdsPlugin*) plugin;

@end

NS_ASSUME_NONNULL_END
