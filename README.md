# COBS for C++
## Abstract
数値データをエンコードしCOBS形式のデータに、またはCOBS形式のデータをデコードし数値データに変換する。
## Usage
  1. 2バイト送信
  ```
  #include <iostream>
  #include "stdint.h"
  #include "COBS/COBS.hpp"
  #include "DISPALY_ARR/display_array.hpp"
  int main()
  {
	  COBS<int16_t> a(2,2);
	  float d[4]={-214.4,2.3,-4.23,22};
	  uint8_t c[10];
	  float e[6];
	  std::cout<<a.get_data_size()<<std::endl;
	  a.encode(d,4,c);
	  display_array(c,10);
	  a.decode(c,10,e);
	  display_array(e,4);
  }
  ```
  1. 4バイト送信
  ```
  #include <iostream>
  #include "stdint.h"
  #include "COBS/COBS.hpp"
  #include "DISPALY_ARR/display_array.hpp"
  int main()
  {
	  COBS<int32_t> a(4,2);
	  float d[3]={-262144,-4.23};
	  uint8_t c[11];
	  float e[6];
	  std::cout<<a.get_data_size()<<std::endl;
	  a.encode(d,3,c);
    display_array(c,14);
	  a.decode(c,14,e);
	  display_array(e,3);
  }
  ```
## History
2022/08/11 リポジトリの作成
