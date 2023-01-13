import 'dart:io';

import 'package:flutter/services.dart';
import 'package:flutter/widgets.dart';

/// Banner 广告组件
class AdBannerWidget extends StatefulWidget {
  const AdBannerWidget({
    Key? key,
    required this.posId,
    this.width = 300,
    this.height = 150,
    this.show = true,
  }) : super(key: key);
  // 广告 id
  final String posId;
  // 创建 Banner 广告位时选择的宽度，默认值是 300
  final int width;
  // 创建 Banner 广告位时选择的高度，默认值是 150
  final int height;
  // 是否显示广告
  final bool show;

  @override
  _AdBannerWidgetState createState() => _AdBannerWidgetState();
}

class _AdBannerWidgetState extends State<AdBannerWidget>
    with AutomaticKeepAliveClientMixin {
  // View 类型
  final String viewType = 'flutter_gromore_ads_banner';
  // 创建参数
  late Map<String, dynamic> creationParams;

  @override
  void initState() {
    creationParams = <String, dynamic>{
      "posId": widget.posId,
      "width": widget.width,
      "height": widget.height,
    };
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    super.build(context);
    if (!widget.show) {
      return const SizedBox.shrink();
    }
    if (Platform.isIOS) {
      return SizedBox.fromSize(
        size: Size(widget.width.toDouble(), widget.height.toDouble()),
        child: UiKitView(
          viewType: viewType,
          creationParams: creationParams,
          creationParamsCodec: const StandardMessageCodec(),
        ),
      );
    } else {
      return SizedBox.fromSize(
        size: Size(widget.width.toDouble(), widget.height.toDouble()),
        child: AndroidView(
          viewType: viewType,
          creationParams: creationParams,
          creationParamsCodec: const StandardMessageCodec(),
        ),
      );
    }
  }

  @override
  bool get wantKeepAlive => true;
}
