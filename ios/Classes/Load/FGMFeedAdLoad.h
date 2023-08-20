//
//  FeedAdLoad.h
//  flutter_pangle_ads
//
//  Created by zero on 2021/11/29.
//

#import <Foundation/Foundation.h>
#import "FGMBasePage.h"

@interface FGMFeedAdLoad : FGMBasePage<BUNativeAdsManagerDelegate>
@property (strong,nonatomic,nonnull) FlutterResult result;
@property (strong,nonatomic,nullable) BUNativeAdsManager *adManager;
// 加载信息流广告列表
-(void) loadFeedAdList:(nonnull FlutterMethodCall *)call result:(nonnull FlutterResult) result eventSink:(nonnull FlutterEventSink )events;
@end
