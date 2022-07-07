//
//  ABUSigmobBannerAdapter.h
//  ABUAdSigmobAdapter
//
//  Created by ByteDance on 2022/4/3.
//

#import <Foundation/Foundation.h>
# if __has_include(<ABUAdSDK/ABUAdSDK.h>)
#import <ABUAdSDK/ABUAdSDK.h>
#else
#import <Ads-Mediation-CN/ABUAdSDK.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ABUSigmobBannerAdapter : NSObject <ABUCustomBannerAdapter>

@end

NS_ASSUME_NONNULL_END
