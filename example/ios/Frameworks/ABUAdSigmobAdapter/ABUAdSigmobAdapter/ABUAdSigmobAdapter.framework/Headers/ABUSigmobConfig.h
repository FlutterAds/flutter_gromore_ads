//
//  ABUSigmobConfig.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/31.
//

#import <Foundation/Foundation.h>
# if __has_include(<ABUAdSDK/ABUAdSDK.h>)
#import <ABUAdSDK/ABUAdSDK.h>
#else
#import <Ads-Mediation-CN/ABUAdSDK.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ABUSigmobConfig : NSObject <ABUCustomConfigAdapter>

@end

NS_ASSUME_NONNULL_END
