//
//  ABUAdapterRegister.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/24.
//

#import <Foundation/Foundation.h>
#import "ABUCustomConfigAdapter.h"

NS_ASSUME_NONNULL_BEGIN

typedef id<ABUCustomConfigAdapter>_Nonnull(ABUSameAdnAdapterBattleFunction)(NSArray<id<ABUCustomConfigAdapter>> *);

FOUNDATION_EXPORT void ABUSameAdnAdapterBattleFunctionRegister(ABUSameAdnAdapterBattleFunction *function);

#if !defined(ABU_ADAPTER_REGISTER)
#define ABU_ADAPTER_REGISTER(__adn_key__,__config_class__) \
@implementation ABUAdapterRegister (__config_class__) \
-(id<ABUCustomConfigAdapter>)__ABU__##__adn_key__{ \
return (id<ABUCustomConfigAdapter>)[[__config_class__ alloc] init]; \
}\
@end
#endif

@interface ABUAdapterRegister : NSObject


@end

NS_ASSUME_NONNULL_END
