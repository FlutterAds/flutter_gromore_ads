//
//  ABUCarouselView.h
//  ABUCarouselView
//
//  Created by zth on 2021/10/9.
//

#import <UIKit/UIKit.h>
#import "ABUCarouselViewModel.h"

NS_ASSUME_NONNULL_BEGIN
/// 轮播视图View(Base)
@interface ABUCarouselView : UIView

/// 初始化
/// @param viewModel vm
- (instancetype)initWithViewModel:(__kindof ABUCarouselViewModel *)viewModel;

/// 加载adview
/// @param view a ad view
- (__kindof ABUCarouselView *)loadAdView:(UIView * _Nullable)view;

@end
# pragma mark - Banner

/// 轮播视图View(Banner)
@interface ABUBannerCarouselView : ABUCarouselView

@end

NS_ASSUME_NONNULL_END
