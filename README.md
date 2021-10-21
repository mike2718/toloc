# 将度分秒格式的经纬度转换为梅登黑德网格定位系统位置字符串的C程序
  
将《业余无线电通信》（第五版）第34页的BASIC程序翻译为C程序，使其能够在现代Linux上运行。

## 使用方法

将度分秒转换为为梅登黑德字符串：

`$ pcc -Wall -Wpedantic -Wextra -Werror -Wcast-qual -O0 -std=c11 -o dmstoloc dmstoloc.c && ./dmstoloc`
