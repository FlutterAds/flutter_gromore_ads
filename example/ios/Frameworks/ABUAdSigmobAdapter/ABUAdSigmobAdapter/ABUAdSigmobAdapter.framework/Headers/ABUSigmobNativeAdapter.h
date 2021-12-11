//
//  ABUSigmobNativeAdapter.h
//  ABUAdSDK
//
//  Created by heyinyin on 2021/10/20.
//

#import <Foundation/Foundation.h>
# if __has_include(<ABUAdSDK/ABUAdSDK.h>)
#import <ABUAdSDK/ABUAdSDK.h>
#else
#import <Ads-Mediation-CN/ABUAdSDK.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ABUSigmobNativeAdapter : NSObject <ABUCustomNativeAdapter>

@end

NS_ASSUME_NONNULL_END
