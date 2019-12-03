// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^MSHttpRequestCompletionHandler)(NSData *_Nullable responseBody, NSHTTPURLResponse *_Nullable response,
                                               NSError *_Nullable error);
@class MSHttpCall;
@protocol MSHttpClientDelegate;

@protocol MSHttpClientProtocol

@required

/**
 * Make an HTTP call.
 *
 * @param url The endpoint to use in the HTTP request.
 * @param method The HTTP method (verb) to use for the HTTP request (e.g. GET, POST, etc.).
 * @param headers HTTP headers.
 * @param data A data instance that will be transformed request body.
 * @param completionHandler Completion handler.
 *
 *@return The created HTTP call.
 */
- (MSHttpCall *)sendAsync:(NSURL *)url
               method:(NSString *)method
              headers:(nullable NSDictionary<NSString *, NSString *> *)headers
                 data:(nullable NSData *)data
    completionHandler:(nullable MSHttpRequestCompletionHandler)completionHandler;

/**
 * Make an HTTP call.
 *
 * @param url The endpoint to use in the HTTP request.
 * @param method The HTTP method (verb) to use for the HTTP request (e.g. GET, POST, etc.).
 * @param headers HTTP headers.
 * @param data A data instance that will be transformed request body.
 * @param retryIntervals The retry intervals for the request.
 * @param compressionEnabled Whether to compress the request data when it exceeds a certain size.
 * @param completionHandler Completion handler.
 *
 *@return The created HTTP call.
 */
- (MSHttpCall *)sendAsync:(NSURL *)url
           method:(NSString *)method
          headers:(nullable NSDictionary<NSString *, NSString *> *)headers
             data:(nullable NSData *)data
   retryIntervals:(NSArray *)retryIntervals
compressionEnabled:(BOOL)compressionEnabled
 completionHandler:(nullable MSHttpRequestCompletionHandler)completionHandler;

/**
 * Enables or disables the client. All pending requests are canceled and discarded upon disabling.
 *
 * @param isEnabled The desired enabled state of the client - pass `YES` to enable, `NO` to disable.
 */
- (void)setEnabled:(BOOL)isEnabled;

@end

NS_ASSUME_NONNULL_END
