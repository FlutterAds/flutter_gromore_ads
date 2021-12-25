//
//  FGMAdEvent.m
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/11.
//

#import "FGMAdEvent.h"

@implementation FGMAdEvent
- (id)initWithAdId:(NSString *)adId action:(NSString *)action{
    self.adId=adId;
    self.action=action;
    return self;
}

- (NSDictionary *)toMap{
    NSDictionary *data=@{@"adId":self.adId,@"action":self.action};
    return  data;
}
@end
