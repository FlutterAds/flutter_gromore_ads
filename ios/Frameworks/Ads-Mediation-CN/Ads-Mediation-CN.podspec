
Pod::Spec.new do |spec|
  spec.name = 'Ads-Mediation-CN'
  spec.version = '3.9.0.2'
  spec.summary = 'Ads-Mediation-CN is a SDK from Bytedance providing media union AD service.'
  spec.homepage = 'https://www.csjplatform.com/gromore'
  spec.description = <<-DESC
  Ads-Mediation-CN allows you to monetize your iOS  apps with media union ads.  
                       DESC

  spec.license = { :type => 'MIT', :file => 'LICENSE' }
  spec.author = 'makaiwen'

  spec.platform = :ios, '9.0'

  spec.source = { :git => 'https://www.csjplatform.com/gromore' }

  spec.requires_arc = true
  
  spec.pod_target_xcconfig = {'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  spec.user_target_xcconfig = {'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  spec.ios.deployment_target = '9.0'
  valid_archs = ['arm64', 'armv7', 'x86_64', 'i386']

	# 这里不加载 framework 因为在插件中已经加载了
	# spec.ios.vendored_frameworks = 'Ads-Mediation-CN/ABUAdSDK.framework'
  spec.dependency "BURelyFoundation"
  spec.libraries = 'sqlite3', 'xml2', 'z'
  spec.frameworks = 'SystemConfiguration', 'CoreGraphics', 'Foundation', 'UIKit', 'AdSupport', 'StoreKit', 'QuartzCore', 'CoreTelephony', 'MobileCoreServices', 'Accelerate', 'AVFoundation', 'WebKit'

end
