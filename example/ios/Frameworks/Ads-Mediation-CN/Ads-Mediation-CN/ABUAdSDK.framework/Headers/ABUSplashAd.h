//
//  ABUNewSplashAd.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/6/8.
//

#import "ABUBaseAd.h"
#import "ABUSplashZoomOutView.h"
#import "ABUSplashCardView.h"
#import "ABUSplashUserData.h"
#import "ABUAdSDKConst.h"

NS_ASSUME_NONNULL_BEGIN

@class ABUSplashAd;
@class ABUAdPackage;
@class ABUDictionary;

/// 开屏广告回调协议
@protocol ABUSplashAdDelegate <NSObject>

@optional

/// 广告加载成功回调
/// @param splashAd 广告管理对象
- (void)splashAdDidLoad:(ABUSplashAd *)splashAd;

/// 广告加载失败回调
/// @param splashAd 广告管理对象
/// @param error 出错信息
- (void)splashAd:(ABUSplashAd *)splashAd didFailWithError:(NSError *_Nullable)error;

/// 广告展示回调(此回调兼容adn sdk的willVisible & didVisible回调,处理特殊逻辑时,请谨慎使用)
/// @param splashAd 广告管理对象
- (void)splashAdWillVisible:(ABUSplashAd *)splashAd;

/// 广告展示失败回调
/// @param splashAd 广告管理对象
/// @param error 展示失败原因
- (void)splashAdDidShowFailed:(ABUSplashAd *_Nonnull)splashAd error:(NSError *)error;

/// 广告点击事件回调
/// @param splashAd 广告管理对象
- (void)splashAdDidClick:(ABUSplashAd *)splashAd;

/// 广告关闭事件回调
/// @param splashAd 广告管理对象
- (void)splashAdDidClose:(ABUSplashAd *)splashAd;

/// 广告即将展示广告详情页回调
/// @param splashAd 广告管理对象
- (void)splashAdWillPresentFullScreenModal:(ABUSplashAd *)splashAd;

/// 关闭广告详情页回调
/// @param splashAd 广告管理对象
- (void)splashAdWillDismissFullScreenModal:(ABUSplashAd *)splashAd;

/// 广告倒计时结束回调
/// @param splashAd 广告管理对象
- (void)splashAdCountdownToZero:(ABUSplashAd *)splashAd;

/// 模板开屏广告播放完成回调
/// @param splashAd 广告管理对象
/// @param error 播放出现的错误信息
- (void)splashAd:(ABUSplashAd *)splashAd didPlayFinishWithError:(NSError *)error;

/// 开屏广告播放完成回调
/// @param splashAd 广告管理对象
/// @param error 播放出现的错误信息
- (void)splashAdExpressViewDidPlayFinish:(ABUSplashAd *)splashAd error:(NSError *)error ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用 splashAd:didPlayFinishWithError:");
@end

/// 开屏广告管理类
@interface ABUSplashAd : ABUBaseAd

/// 广告位ID，只读
@property (readonly) NSString *adUnitID;

/// 开屏广告构建方法
/// @param unitID 广告位ID
- (instancetype)initWithAdUnitID:(NSString *)unitID;

/// 代理回调对象
@property (nonatomic, weak) id<ABUSplashAdDelegate> delegate;

/// 最大等待加载时长，单位秒，，默认3秒。实现由adapter确定
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

/// 是否需要开启zoomout功能，需要ADN及adapter支持
@property (nonatomic, assign) BOOL needZoomOutIfCan;

/// 【必选】广告事件跳转控制器
@property (nonatomic, weak, nullable) UIViewController *rootViewController;

/// 展示广告
/// @param window 展示window，具体由adapter实现
- (BOOL)showInWindow:(UIWindow *)window;

/// [可选]在广告位配置拉取失败后，会使用传入的rit和appID兜底，进行广告加载，需要在创建manager时就调用该接口
- (void)setUserData:(ABUSplashUserData *)userData error:(NSError **)error;

/// 自定义底部视图，可以设置一些自定义元素，例如LOGO。如果不设置，广告将按照全屏展示。底部视图最大高度不能超过屏幕高度的25%，否则将按照约定最大高度适配
@property (nonatomic, strong, nullable) UIView *customBottomView;

/// 销毁广告，建议在不需要展示广告时调用，如close时
- (void)destoryAd;

/// optional. Config the behaviour of click splash view.Deafult value is ABUSplashButtonTypeFullScreen.Now only valid for adn:pangle, baidu.
@property (nonatomic, assign) ABUSplashButtonType splashButtonType;

/// zoom out 视图，需adn和adapter支持，可能为空
@property (nonatomic, strong, readonly, nullable) ABUSplashZoomOutView *zoomOutView;

/// The display priority of cardview is higher than that of zoomview. Now only valid for adn:pangle.
@property (nonatomic, assign) BOOL supportCardView; // default is NO

/// When it is support splash card advertisement, it has value. Now only valid for adn:pangle.
@property (nonatomic, strong, readonly, nullable) ABUSplashCardView *cardView;

@property (nonatomic, assign, readonly) BOOL isReady;

/// 广告的扩展信息，可能为nil
- (ABUDictionary *_Nullable)extraData;

/// 返回显示广告对应的rit
- (NSString *)getAdNetworkRitId ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用`getShowEcpmInfo`代替");

/// 返回显示广告对应的ecpm，当没有权限访问该部分会返回-3 单位：分
- (NSString *)getPreEcpm ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用`getShowEcpmInfo`代替");

/// 返回显示广告对应的Adn名称
- (NSString *)getAdNetworkPlatformName ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用`getShowEcpmInfo`代替");

/// 返回显示广告对应的披露信息，当没有权限访问时Ecpm会返回'-3'
- (ABURitInfo *)getShowEcpmInfo;

/// 填充后可调用，返回当前最佳广告的ecpm；当为server bidding ad时访问需要白名单权限；nil为无权限
- (ABURitInfo *)getCurrentBestEcpmInfo;

/// 填充后可调用，但推荐展示后调用，返回竞价广告的ecpm；当为server bidding ad时访问需要白名单权限；
- (NSArray<ABURitInfo *> *)multiBiddingEcpmInfos;

/// 填充后可调用, 返回广告缓存池内所有信息；nil为无权限
- (NSArray<ABURitInfo *> *)cacheRitList;

/// 填充后可调用，获取广告中的extra信息。目前只支持穿山甲，并且只支持获取coupon, live_room, product信息。
- (nullable NSDictionary *)getMediaExtraInfo;

@end

NS_ASSUME_NONNULL_END
