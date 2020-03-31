#import <Foundation/Foundation.h>
#import "CleverTap+ProductConfig.h"

@protocol CleverTapPrivateProductConfigDelegate <NSObject>
@required

@property (atomic, weak) id<CleverTapProductConfigDelegate> _Nullable productConfigDelegate;

- (void)fetchProductConfig;

- (void)activateProductConfig;

- (void)fetchAndActivateProductConfig;

- (void)setDefaultsProductConfig:(NSDictionary<NSString *, NSObject *> *_Nullable)defaults;

- (void)setDefaultsFromPlistFileNameProductConfig:(NSString *_Nullable)fileName;

- (CleverTapConfigValue *_Nullable)getProductConfig:(NSString* _Nonnull)key;

@end

@interface CleverTapConfigValue() {}

- (instancetype _Nullable )initWithData:(NSData *_Nullable)data;

@end


@interface CleverTapProductConfig () {}

// TODO: name can be minFetchConfigRate or minFetchRate
@property(nonatomic, assign) NSTimeInterval minFetchConfigRate;
@property(nonatomic, assign) NSTimeInterval minFetchConfigInterval;
@property(nonatomic, assign) NSTimeInterval lastFetchTimeInterval;

@property (nonatomic, weak) id<CleverTapPrivateProductConfigDelegate> _Nullable privateDelegate;

- (instancetype _Nullable)init __unavailable;

- (instancetype _Nonnull)initWithPrivateDelegate:(id<CleverTapPrivateProductConfigDelegate> _Nonnull)delegate;

- (void)updateProductConfigWithOptions:(NSDictionary *_Nullable)options;

- (void)updateProductConfigWithLastFetchTs:(NSTimeInterval)lastFetchTs;
@end
