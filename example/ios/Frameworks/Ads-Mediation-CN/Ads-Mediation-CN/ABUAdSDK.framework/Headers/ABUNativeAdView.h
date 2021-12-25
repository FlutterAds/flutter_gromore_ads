//
//  ABUMediatedNativeAd.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/6/9.
//

#import <Foundation/Foundation.h>
#import "ABUNativeAdView.h"
#import "ABUImage.h"
#import "ABUMediatedNativeAdData.h"
#import "ABUNativeAdViewDelegate.h"
#import "ABUNativeAdVideoDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class ABUNativeAdsManager;

/// native广告视图类
@interface ABUNativeAdView : UIView

/// 广告管理者
@property (nonatomic, weak, readonly) ABUNativeAdsManager *adManager;

/// 代理协议对象
@property (nonatomic, weak, readwrite, nullable) id<ABUNativeAdViewDelegate> delegate;

/// 视频播放代理协议对象
@property (nonatomic, weak, readwrite, nullable) id<ABUNativeAdVideoDelegate> videoDelegate;

/// 是否是模板广告，由adapter开发者实现
@property (nonatomic, assign, readonly) BOOL isExpressAd;

/// 非模板Native广告的物料数据，模板广告时为nil
@property (nonatomic, strong, readonly, nullable) ABUMaterialMeta *data;

/// 是否是模板广告，由adapter开发者实现，同isExpressAd
@property (nonatomic, assign, readonly) BOOL hasExpressAdGot;

/// [必传]跳转控制器
@property (nonatomic, weak, readwrite) UIViewController *_Nullable rootViewController;

/// 返回显示广告对应的Adn，当广告加载中未显示会返回-2，当没有权限访问该部分会返回-3
- (ABUAdnType)getAdNetworkPlaformId;

/// 返回显示广告对应的rit，当广告加载中未显示会返回-2，当没有权限访问该部分会返回-3
- (NSString *_Nullable)getAdNetworkRitId;

/// 返回显示广告对应的ecpm，当未在平台配置ecpm会返回-1，当广告加载中未显示会返回-2，当没有权限访问该部分会返回-3 单位：分
- (NSString *_Nullable)getPreEcpm;

/// 返回显示广告对应的Adn名称，当广告加载中未显示会返回-2，当没有权限访问该部分会返回-3
- (NSString *)getAdNetworkPlatformName;

/// 广告视图的唯一标识
@property (nonatomic, copy, readonly) NSString *adViewID;

@end

/// native广告视图类，非模板部分
/// 📢 以下描述需开发者自己渲染UI内容处，存在部分AND已强制处理或adapter代为处理，外部开发者需注意
@interface ABUNativeAdView (Native)

/// 是否支持自定义事件按钮，如果为YES，开发者可以配置 callToActionBtn 的UI数值，默认为YES
@property (nonatomic, assign, readonly) BOOL hasSupportActionBtn;

/// 广告标题，需要开发者根据广告物料自己指定展示内容
@property (nonatomic, strong, readonly, nonnull) UILabel *titleLabel;

/// 广告描述，需要开发者根据广告物料自己指定展示内容
@property (nonatomic, strong, readonly, nonnull) UILabel *descLabel;

/// 广告图标，可能不存在，需要开发者根据广告物料自己指定展示内容
@property (nonatomic, strong, nullable) UIImageView *iconImageView;

/// 广告大图，需要开发者根据广告物料自己指定展示内容，系统会自动创建，但内容需开发者自行校验
@property (nonatomic, strong, readonly, nullable) UIImageView *imageView;

/// Ad CTA button. Need to be assigned from a data(ABUMaterialMeta), and need to be add to self(ABUNativeAdView).

/// 广告详情/下载按钮，可能不存在，文案内容需要开发者根据广告物料自己获取
@property (nonatomic, strong, readonly, nonnull) UIButton *callToActionBtn;

/// 广告商视图，可能不存在，开发者可自行赋值处理
@property (nonatomic, strong, nullable) UIView *advertiserView;

/// 广告关闭按钮，可能不存在，开发者需自行处理响应事件
@property (nonatomic, strong, nullable) UIButton *dislikeBtn;

/// 广告LOGO视图，可能不存在，需要开发者根据广告物料自己指定展示内容
@property (nonatomic, strong, nullable) UIView *adLogoView;

/// 媒体视图，即视频广告的视频图层，非视频广告不存在该视图
@property (nonatomic, strong, readonly, nullable) UIView *mediaView;

/// 注册可点击区域，由GroMore透传数据，是否生效由adapter 和 adn 决定
/// @param views 可响应点击操作的视图
- (void)registerClickableViews:(nullable NSArray<UIView *> *)views;

@end

/// native广告视图类，模板部分
@interface ABUNativeAdView (Express)

/// [必要]渲染模板广告，开发者调用前无需区分是否为模板广告，GroMore会自行处理
- (void)render;

/// [保留方法]更新模板媒体视图大小
- (void)reSizeMediaView;

@end

NS_ASSUME_NONNULL_END
