import 'package:flutter/material.dart';

/// Pro 页面
class ProPage extends StatefulWidget {
  const ProPage({Key? key}) : super(key: key);

  @override
  State<ProPage> createState() => _ProPageState();
}

class _ProPageState extends State<ProPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Pro 付费功能'),
      ),
      body: SingleChildScrollView(
        child: Column(
          children: [
            const Center(
              child: Padding(
                padding: EdgeInsets.all(10.0),
                child: Text(
                  '此功能是插件 Pro 付费功能，需要购买插件后才能使用\n请联系微信：toponelan 咨询购买并获得技术支持',
                  textAlign: TextAlign.center,
                ),
              ),
            ),
            Image.asset(
              'assets/images/img_pro.png',
              fit: BoxFit.cover,
            ),
            const Center(
              child: Padding(
                padding: EdgeInsets.all(10.0),
                child: Text(
                  '日活 10W 以上，可咨询其他合作模式，目前已合作百万级别的 App 客户',
                  textAlign: TextAlign.center,
                  style: TextStyle(
                    color: Colors.purple,
                    fontSize: 16,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
