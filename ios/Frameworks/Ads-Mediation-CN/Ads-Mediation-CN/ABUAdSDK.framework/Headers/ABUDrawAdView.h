//
//  ABUDrawVideoAdView.h
//  ABUAdKsAdapter
//
//  Created by heyinyin on 2022/4/7.
//

#import "ABUCanvasView.h"

#import "ABUDrawAdsManager.h"
#import "ABUImage.h"
#import "ABUDrawAdViewDelegate.h"
#import "ABUDrawAdVideoDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class ABUDrawAdsManager, ABURitInfo, ABUVideoAdReporter;
@class ABUDictionary;

@interface ABUDrawAdView : ABUCanvasView
/// 广告管理者
@property (nonatomic, weak, readonly) ABUDrawAdsManager *adManager;

/// 代理协议对象
@property (nonatomic, weak, readwrite, nullable) id<ABUDrawAdViewDelegate> delegate;

/// 视频播放代理协议对象
@property (nonatomic, weak, readwrite, nullable) id<ABUDrawAdVideoDelegate> videoDelegate;

/// 是否是模板广告，由adapter开发者实现
@property (nonatomic, assign, readonly) BOOL isExpressAd;

/// 是否是模板广告，由adapter开发者实现，同isExpressAd
@property (nonatomic, assign, readonly) BOOL hasExpressAdGot;

/// [必传]跳转控制器
@property (nonatomic, weak, readwrite) UIViewController *_Nullable rootViewController;

/// 返回显示广告对应的披露信息，当没有权限访问时Ecpm会返回'-3'
- (nullable ABURitInfo *)getShowEcpmInfo;

/// 填充后可调用，但推荐展示后调用，返回竞价广告的ecpm；当为server bidding ad时访问需要白名单权限；
- (NSArray<ABURitInfo *> *)multiBiddingEcpmInfos;

/// 填充后可调用, 返回广告缓存池内所有信息；nil为无权限
- (NSArray<ABURitInfo *> *)cacheRitList;

/// 填充后可调用，返回当前最佳广告的ecpm；当为server bidding ad时访问需要白名单权限
- (ABURitInfo *)getCurrentBestEcpmInfo;

/// 广告的扩展信息，可能为nil
- (ABUDictionary *_Nullable)extraData;

/// 填充后可调用，获取广告中的extra信息。目前只支持穿山甲，并且只支持获取coupon, live_room, product信息。
- (nullable NSDictionary *)getMediaExtraInfo;

/// 广告视图的唯一标识
@property (nonatomic, copy, readonly) NSString *adViewID;
@end
/// draw广告视图类，模板部分
@interface ABUDrawAdView (Express)

/// 是否已经准备广告展示，理论上在广告加载回调后即为YES，但受一些因素的影响（例如广告失效），可能为NO。建议在广告展示前调用该方法进行是否可以展示
@property (nonatomic, assign, readonly) BOOL isReady;

/// 返回显示广告对应的Adn名称
/// [必要]渲染模板广告，开发者调用前无需区分是否为模板广告，GroMore会自行处理
- (void)render;

/// [保留方法]更新模板媒体视图大小
- (void)reSizeMediaView;

@end

@interface ABUDrawAdView (Native)

/// 自渲染视频类广告事件上报对象，仅采用自定义视频播放器时需要上报，部分ADN需申请白名单
@property (nonatomic, strong, readonly) ABUVideoAdReporter *videoAdReporter;

@end

NS_ASSUME_NONNULL_END
