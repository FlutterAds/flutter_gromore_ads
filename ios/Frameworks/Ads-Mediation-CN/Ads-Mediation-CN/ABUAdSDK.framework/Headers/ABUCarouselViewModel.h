//
//  ABUCarouselViewModel.h
//  ABUCarouselViewModel
//
//  Created by zth on 2021/10/9.
//

#import <Foundation/Foundation.h>

# pragma mark - 基类

typedef void(^ABUCarouseUpdateAdViewBlock)(UIView *_Nullable adView);
typedef void(^ABUCarouseRequestAdViewBlock)(BOOL request);

NS_ASSUME_NONNULL_BEGIN

/// 轮播视图View Model (Base)
@interface ABUCarouselViewModel : NSObject

/// 是否开启轮播功能, 默认为NO
@property (nonatomic, assign, readonly) BOOL carouseEnable;

/// 轮播是否开始, 默认为NO, 当轮播视图加载adview时, 更新为YES
/// @Note carouseHaveStart 更新为YES的前提是 carouseEnable = YES
@property (nonatomic, assign, readonly) BOOL carouseHaveStart;

/// 轮播时长  只有轮播时长 > 0时 才可以进行轮播,  单位为秒
@property (nonatomic, assign, readonly) NSInteger carouseDuration;

/// 更新ad View回调Block
@property (nonatomic, copy) ABUCarouseUpdateAdViewBlock adViewUpdateHandle;

/// 界面开始轮播时,请求下一次的adview
@property (nonatomic, copy) ABUCarouseRequestAdViewBlock adViewRequestHandle;


/// 记录广告View
/// @param view 广告 View
- (void)recordAdView:(UIView *)view;

/// 是否可以记录, 返回为NO时, 不再进行轮播的ad请求
/// @Note 防止无限次进行轮播请求
- (BOOL)recordEnable;

/// 记录的广告个数
- (NSInteger)recordNum;

/// 开始轮播
- (void)carouseStart;

/// 取消轮播
- (void)carouseCancel;

/// 处理轮播设置数据
- (void)loadCarouseWithSetUpData:(id)setupData;


@end

# pragma mark - Banner

/// 轮播视图View Model (Banner)
@interface ABUBannerCarouselViewModel : ABUCarouselViewModel



@end

NS_ASSUME_NONNULL_END
