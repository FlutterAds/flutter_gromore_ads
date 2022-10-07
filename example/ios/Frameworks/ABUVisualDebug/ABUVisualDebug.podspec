
Pod::Spec.new do |spec|

  spec.name         = 'ABUVisualDebug'
  spec.version      = '3.7.0.0'
  spec.summary      = 'ABUVisualDebug is a debug SDK for Bytedance GroMore'
  spec.homepage     = 'https://www.csjplatform.com/gromore'
  spec.description  = <<-DESC   
              ABUVisualDebug is a debug SDK for Bytedance GroMore.
                       DESC

  spec.license      = { :type => 'MIT', :file => 'LICENSE' }
  spec.author       = 'makaiwen'
  
  spec.platform     = :ios, '9.0'

  spec.source = { :git => 'https://www.csjplatform.com/gromore' }

  spec.requires_arc = true
  # spec.user_target_xcconfig =   {'OTHER_LDFLAGS' => ['-lObjC']}
  spec.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
  spec.ios.deployment_target = '9.0'

  valid_archs = ['arm64', 'armv7', 'x86_64', 'i386']

	spec.ios.vendored_frameworks = 'ABUVisualDebug/ABUVisualDebug.framework'
	spec.resource = 'ABUVisualDebug/ABUVisualDebug.bundle'
  spec.dependency 'Ads-Mediation-CN'
  spec.dependency "BURelyFoundation"

end
