//
//  ABUSigmobNativeAdData.h
//  ABUAdSDK
//
//  Created by heyinyin on 2021/10/21.
//

#import <Foundation/Foundation.h>
# if __has_include(<ABUAdSDK/ABUAdSDK.h>)
#import <ABUAdSDK/ABUAdSDK.h>
#else
#import <Ads-Mediation-CN/ABUAdSDK.h>
#endif
#import "ABUSigmobProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@interface ABUSigmobNativeAdData : NSObject <ABUMediatedNativeAdData, ABUMediatedNativeAdViewCreator>
- (instancetype)initWithOriginData:(WindNativeAd *)data andView:(WindNativeAdView *)adview;

@property (nonatomic, copy) NSArray<UIImageView *> *imageViewList;
@end

NS_ASSUME_NONNULL_END
