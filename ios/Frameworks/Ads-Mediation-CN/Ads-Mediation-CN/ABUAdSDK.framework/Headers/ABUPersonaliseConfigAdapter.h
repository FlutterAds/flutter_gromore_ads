//
//  ABUPersonaliseConfigAdapter.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 个性化配置类
@interface ABUPersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithKey:(NSString *)key andBlock:(void(^)(void))block;

@end

FOUNDATION_EXTERN API_DEPRECATED("ABUUnityPersonaliseConfigAdapter is deprecated. Use ABUPersonaliseConfigAdapter with a key 'unity' of network instead", ios(2.0, 9.0))
@interface ABUUnityPersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithBlock:(void(^)(void))block API_DEPRECATED("Use ABUPersonaliseConfigAdapter instead.", ios(2.0, 9.0));

@end

FOUNDATION_EXTERN API_DEPRECATED("ABUAdmobPersonaliseConfigAdapter is deprecated. Use ABUPersonaliseConfigAdapter with a key 'admob' of network instead", ios(2.0, 9.0))
@interface ABUAdmobPersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithBlock:(void(^)(void))block API_DEPRECATED("Use ABUPersonaliseConfigAdapter instead.", ios(2.0, 9.0));

@end

FOUNDATION_EXTERN API_DEPRECATED("ABUBaiduPersonaliseConfigAdapter is deprecated. Use ABUPersonaliseConfigAdapter with a key 'baidu' of network instead", ios(2.0, 9.0))
@interface ABUBaiduPersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithBlock:(void(^)(void))block API_DEPRECATED("Use ABUPersonaliseConfigAdapter instead.", ios(2.0, 9.0));

@end

FOUNDATION_EXTERN API_DEPRECATED("ABUPanglePersonaliseConfigAdapter is deprecated. Use ABUPersonaliseConfigAdapter with a key 'pangle' of network instead", ios(2.0, 9.0))
@interface ABUPanglePersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithBlock:(void(^)(void))block API_DEPRECATED("Use ABUPersonaliseConfigAdapter instead.", ios(2.0, 9.0));

@end

FOUNDATION_EXTERN API_DEPRECATED("ABUGdtPersonaliseConfigAdapter is deprecated. Use ABUPersonaliseConfigAdapter with a key 'gdt' of network instead", ios(2.0, 9.0))
@interface ABUGdtPersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithBlock:(void(^)(void))block API_DEPRECATED("Use ABUPersonaliseConfigAdapter instead.", ios(2.0, 9.0));

@end

FOUNDATION_EXTERN API_DEPRECATED("ABUMintegralPersonaliseConfigAdapter is deprecated. Use ABUPersonaliseConfigAdapter with a key 'mintegral' of network instead", ios(2.0, 9.0))
@interface ABUMintegralPersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithBlock:(void(^)(void))block API_DEPRECATED("Use ABUPersonaliseConfigAdapter instead.", ios(2.0, 9.0));

@end

FOUNDATION_EXTERN API_DEPRECATED("ABUSigmobPersonaliseConfigAdapter is deprecated. Use ABUPersonaliseConfigAdapter with a key 'sigmob' of network instead", ios(2.0, 9.0))
@interface ABUSigmobPersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithBlock:(void(^)(void))block API_DEPRECATED("Use ABUPersonaliseConfigAdapter instead.", ios(2.0, 9.0));

@end

FOUNDATION_EXTERN API_DEPRECATED("ABUKsPersonaliseConfigAdapter is deprecated. Use ABUPersonaliseConfigAdapter with a key 'ks' of network instead", ios(2.0, 9.0))
@interface ABUKsPersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithBlock:(void(^)(void))block API_DEPRECATED("Use ABUPersonaliseConfigAdapter instead.", ios(2.0, 9.0));

@end

FOUNDATION_EXTERN API_DEPRECATED("ABUKlevinPersonaliseConfigAdapter is deprecated. Use ABUPersonaliseConfigAdapter with a key 'klevin' of network instead", ios(2.0, 9.0))
@interface ABUKlevinPersonaliseConfigAdapter : NSObject

+ (void)configAdapterWithBlock:(void(^)(void))block API_DEPRECATED("Use ABUPersonaliseConfigAdapter instead.", ios(2.0, 9.0));

@end

NS_ASSUME_NONNULL_END
