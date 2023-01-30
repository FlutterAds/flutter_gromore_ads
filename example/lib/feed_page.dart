import 'package:flutter/material.dart';
import 'package:flutter_gromore_ads/flutter_gromore_ads.dart';
import 'package:flutter_gromore_ads/view/ad_feed_widget.dart';
import 'package:flutter_gromore_ads_example/ads_config.dart';
import 'package:loadany/loadany.dart';

/// 信息流页面
class FeedPage extends StatefulWidget {
  const FeedPage({Key? key}) : super(key: key);

  @override
  _FeedPageState createState() => _FeedPageState();
}

class _FeedPageState extends State<FeedPage> {
  List<int> feedList = [];
  List<int> feedAdList = [];

  LoadStatus loadStatus = LoadStatus.normal;

  @override
  void initState() {
    getFeedList();
    super.initState();
  }

  @override
  void dispose() {
    clearFeedAd();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('信息流（FlutterAds）'),
      ),
      body: LoadAny(
        onLoadMore: () async {
          getFeedList();
        },
        status: loadStatus,
        child: CustomScrollView(
          slivers: [
            SliverList(
              delegate: SliverChildBuilderDelegate(
                (BuildContext context, int index) {
                  if (index % 5 == 3) {
                    int adIndex = index ~/ 5;
                    print('adIndex:$adIndex');
                    if (adIndex >= feedAdList.length) {
                      return Container(
                        height: 80,
                        width: double.maxFinite,
                        color: Colors.blueAccent,
                        alignment: Alignment.centerLeft,
                        child: Text('暂无广告 $index'),
                      );
                    }

                    int adId = feedAdList[adIndex];
                    return AdFeedWidget(
                      posId: '$adId',
                      width: 360,
                      height: 120,
                      show: true,
                    );
                  }
                  return const LoadingItemWidget();
                },
                childCount: feedList.length,
              ),
            )
          ],
        ),
      ),
    );
  }

  /// 加载信息流
  Future<void> getFeedList() async {
    setState(() {
      loadStatus = LoadStatus.loading;
    });
    await Future.delayed(Duration(seconds: 1));
    for (var i = 0; i < 15; i++) {
      feedList.add(i);
    }
    getFeedAdList();
  }

  // 加载信息流广告
  Future<void> getFeedAdList() async {
    try {
      List<int> adResultList = await FlutterGromoreAds.loadFeedAd(
        AdsConfig.feedId,
        count: 3,
      );
      feedAdList.addAll(adResultList);
    } catch (e) {
      print(e.toString());
    }
    setState(() {
      loadStatus = LoadStatus.normal;
    });
  }

  // 清除信息流广告
  Future<void> clearFeedAd() async {
    bool result = await FlutterGromoreAds.clearFeedAd(feedAdList);
    print('clearFeedAd:$result');
  }
}

/// 加载项组件
class LoadingItemWidget extends StatelessWidget {
  const LoadingItemWidget({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 80,
      width: double.maxFinite,
      alignment: Alignment.centerLeft,
      padding: EdgeInsets.all(10),
      margin: EdgeInsets.symmetric(vertical: 10),
      color: Colors.white,
      child: Row(
        children: [
          Container(
            width: 60,
            height: 60,
            decoration: BoxDecoration(
              shape: BoxShape.circle,
              color: Color(0xFFEBEBF4),
            ),
          ),
          SizedBox(width: 20),
          Expanded(
            child: Padding(
              padding: const EdgeInsets.all(4),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Container(
                    width: double.maxFinite,
                    height: 20,
                    decoration: BoxDecoration(
                      color: Color(0xFFEBEBF4),
                    ),
                  ),
                  Spacer(),
                  Container(
                    width: 200,
                    height: 20,
                    decoration: BoxDecoration(
                      color: Color(0xFFE4E4F4),
                    ),
                  ),
                ],
              ),
            ),
          )
        ],
      ),
    );
  }
}
