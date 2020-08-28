#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif


#define PIN        6 


#define NUMPIXELS 256 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {

//  for(int r=0;r<=255;r++){
//    for(int g=0;g<=255;g++){
//      for(int b=0;b<=255;b++){
////        AllDisplay(r,g,b);
//        AllDisplay(0,0,0);
//        delay(DELAYVAL);
//      }
//    }
//  }

  AllDisplay(20,20,20);
//  
//  AllDisplay(1,0,0);
//  delay(DELAYVAL);
//  AllDisplay(1,1,0);
//  delay(DELAYVAL);
//  AllDisplay(0,1,0);
//  delay(DELAYVAL);
//  AllDisplay(0,1,1);
//  delay(DELAYVAL);
//  AllDisplay(1,0,1);
//  delay(DELAYVAL);
//  AllDisplay(1,1,1);
//  delay(DELAYVAL);

  



  
//  for(int i=0; i<NUMPIXELS; i++) { 
//    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
//    pixels.show();
//  }
}




void AllDisplay(int R,int G,int B)
{
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B));
  pixels.setPixelColor(4, pixels.Color(R, G, B));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(R, G, B));
  pixels.setPixelColor(7, pixels.Color(R, G, B));
  pixels.setPixelColor(8, pixels.Color(R, G, B));
  pixels.setPixelColor(9, pixels.Color(R, G, B));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(R, G, B));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B));
  pixels.setPixelColor(18, pixels.Color(R, G, B));
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(R, G, B));
  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B));
  pixels.setPixelColor(25, pixels.Color(R, G, B));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(R, G, B));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(R, G, B));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(R, G, B));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(R, G, B));
  pixels.setPixelColor(42, pixels.Color(R, G, B));
  pixels.setPixelColor(43, pixels.Color(R, G, B));
  pixels.setPixelColor(44, pixels.Color(R, G, B));
  pixels.setPixelColor(45, pixels.Color(R, G, B));
  pixels.setPixelColor(46, pixels.Color(R, G, B));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(65, pixels.Color(R, G, B));
  pixels.setPixelColor(66, pixels.Color(R, G, B));
  pixels.setPixelColor(67, pixels.Color(R, G, B));
  pixels.setPixelColor(68, pixels.Color(R, G, B));
  pixels.setPixelColor(69, pixels.Color(R, G, B));
  pixels.setPixelColor(70, pixels.Color(R, G, B));
  pixels.setPixelColor(71, pixels.Color(R, G, B));
  pixels.setPixelColor(72, pixels.Color(R, G, B));
  pixels.setPixelColor(73, pixels.Color(R, G, B));
  pixels.setPixelColor(74, pixels.Color(R, G, B));
  pixels.setPixelColor(75, pixels.Color(R, G, B));
  pixels.setPixelColor(76, pixels.Color(R, G, B));
  pixels.setPixelColor(77, pixels.Color(R, G, B));
  pixels.setPixelColor(78, pixels.Color(R, G, B));
  pixels.setPixelColor(79, pixels.Color(R, G, B));
  pixels.setPixelColor(80, pixels.Color(R, G, B));
  pixels.setPixelColor(81, pixels.Color(R, G, B));
  pixels.setPixelColor(82, pixels.Color(R, G, B));
  pixels.setPixelColor(83, pixels.Color(R, G, B));
  pixels.setPixelColor(84, pixels.Color(R, G, B));
  pixels.setPixelColor(85, pixels.Color(R, G, B));
  pixels.setPixelColor(86, pixels.Color(R, G, B));
  pixels.setPixelColor(87, pixels.Color(R, G, B));
  pixels.setPixelColor(88, pixels.Color(R, G, B));
  pixels.setPixelColor(89, pixels.Color(R, G, B));
  pixels.setPixelColor(90, pixels.Color(R, G, B));
  pixels.setPixelColor(91, pixels.Color(R, G, B));
  pixels.setPixelColor(92, pixels.Color(R, G, B));
  pixels.setPixelColor(93, pixels.Color(R, G, B));
  pixels.setPixelColor(94, pixels.Color(R, G, B));
  pixels.setPixelColor(95, pixels.Color(R, G, B));
  pixels.setPixelColor(96, pixels.Color(R, G, B));
  pixels.setPixelColor(97, pixels.Color(R, G, B));
  pixels.setPixelColor(98, pixels.Color(R, G, B));
  pixels.setPixelColor(99, pixels.Color(R, G, B));
  pixels.setPixelColor(100, pixels.Color(R, G, B));
  pixels.setPixelColor(101, pixels.Color(R, G, B));
  pixels.setPixelColor(102, pixels.Color(R, G, B));
  pixels.setPixelColor(103, pixels.Color(R, G, B));
  pixels.setPixelColor(104, pixels.Color(R, G, B));
  pixels.setPixelColor(105, pixels.Color(R, G, B));
  pixels.setPixelColor(106, pixels.Color(R, G, B));
  pixels.setPixelColor(107, pixels.Color(R, G, B));
  pixels.setPixelColor(108, pixels.Color(R, G, B));
  pixels.setPixelColor(109, pixels.Color(R, G, B));
  pixels.setPixelColor(110, pixels.Color(R, G, B));
  pixels.setPixelColor(111, pixels.Color(R, G, B));
  pixels.setPixelColor(112, pixels.Color(R, G, B));
  pixels.setPixelColor(113, pixels.Color(R, G, B));
  pixels.setPixelColor(114, pixels.Color(R, G, B));
  pixels.setPixelColor(115, pixels.Color(R, G, B));
  pixels.setPixelColor(116, pixels.Color(R, G, B));
  pixels.setPixelColor(117, pixels.Color(R, G, B));
  pixels.setPixelColor(118, pixels.Color(R, G, B));
  pixels.setPixelColor(119, pixels.Color(R, G, B));
  pixels.setPixelColor(120, pixels.Color(R, G, B));
  pixels.setPixelColor(121, pixels.Color(R, G, B));
  pixels.setPixelColor(122, pixels.Color(R, G, B));
  pixels.setPixelColor(123, pixels.Color(R, G, B));
  pixels.setPixelColor(124, pixels.Color(R, G, B));
  pixels.setPixelColor(125, pixels.Color(R, G, B));
  pixels.setPixelColor(126, pixels.Color(R, G, B));
  pixels.setPixelColor(127, pixels.Color(R, G, B));
  pixels.setPixelColor(128, pixels.Color(R, G, B));
  pixels.setPixelColor(129, pixels.Color(R, G, B));
  pixels.setPixelColor(130, pixels.Color(R, G, B));
  pixels.setPixelColor(131, pixels.Color(R, G, B));
  pixels.setPixelColor(132, pixels.Color(R, G, B));
  pixels.setPixelColor(133, pixels.Color(R, G, B));
  pixels.setPixelColor(134, pixels.Color(R, G, B));
  pixels.setPixelColor(135, pixels.Color(R, G, B));
  pixels.setPixelColor(136, pixels.Color(R, G, B));
  pixels.setPixelColor(137, pixels.Color(R, G, B));
  pixels.setPixelColor(138, pixels.Color(R, G, B));
  pixels.setPixelColor(139, pixels.Color(R, G, B));
  pixels.setPixelColor(140, pixels.Color(R, G, B));
  pixels.setPixelColor(141, pixels.Color(R, G, B));
  pixels.setPixelColor(142, pixels.Color(R, G, B));
  pixels.setPixelColor(143, pixels.Color(R, G, B));
  pixels.setPixelColor(144, pixels.Color(R, G, B));
  pixels.setPixelColor(145, pixels.Color(R, G, B));
  pixels.setPixelColor(146, pixels.Color(R, G, B));
  pixels.setPixelColor(147, pixels.Color(R, G, B));
  pixels.setPixelColor(148, pixels.Color(R, G, B));
  pixels.setPixelColor(149, pixels.Color(R, G, B));
  pixels.setPixelColor(150, pixels.Color(R, G, B));
  pixels.setPixelColor(151, pixels.Color(R, G, B));
  pixels.setPixelColor(152, pixels.Color(R, G, B));
  pixels.setPixelColor(153, pixels.Color(R, G, B));
  pixels.setPixelColor(154, pixels.Color(R, G, B));
  pixels.setPixelColor(155, pixels.Color(R, G, B));
  pixels.setPixelColor(156, pixels.Color(R, G, B));
  pixels.setPixelColor(157, pixels.Color(R, G, B));
  pixels.setPixelColor(158, pixels.Color(R, G, B));
  pixels.setPixelColor(159, pixels.Color(R, G, B));
  pixels.setPixelColor(160, pixels.Color(R, G, B));
  pixels.setPixelColor(161, pixels.Color(R, G, B));
  pixels.setPixelColor(162, pixels.Color(R, G, B));
  pixels.setPixelColor(163, pixels.Color(R, G, B));
  pixels.setPixelColor(164, pixels.Color(R, G, B));
  pixels.setPixelColor(165, pixels.Color(R, G, B));
  pixels.setPixelColor(166, pixels.Color(R, G, B));
  pixels.setPixelColor(167, pixels.Color(R, G, B));
  pixels.setPixelColor(168, pixels.Color(R, G, B));
  pixels.setPixelColor(169, pixels.Color(R, G, B));
  pixels.setPixelColor(170, pixels.Color(R, G, B));
  pixels.setPixelColor(171, pixels.Color(R, G, B));
  pixels.setPixelColor(172, pixels.Color(R, G, B));
  pixels.setPixelColor(173, pixels.Color(R, G, B));
  pixels.setPixelColor(174, pixels.Color(R, G, B));
  pixels.setPixelColor(175, pixels.Color(R, G, B));
  pixels.setPixelColor(176, pixels.Color(R, G, B));
  pixels.setPixelColor(177, pixels.Color(R, G, B));
  pixels.setPixelColor(178, pixels.Color(R, G, B));
  pixels.setPixelColor(179, pixels.Color(R, G, B));
  pixels.setPixelColor(180, pixels.Color(R, G, B));
  pixels.setPixelColor(181, pixels.Color(R, G, B));
  pixels.setPixelColor(182, pixels.Color(R, G, B));
  pixels.setPixelColor(183, pixels.Color(R, G, B));
  pixels.setPixelColor(184, pixels.Color(R, G, B));
  pixels.setPixelColor(185, pixels.Color(R, G, B));
  pixels.setPixelColor(186, pixels.Color(R, G, B));
  pixels.setPixelColor(187, pixels.Color(R, G, B));
  pixels.setPixelColor(188, pixels.Color(R, G, B));
  pixels.setPixelColor(189, pixels.Color(R, G, B));
  pixels.setPixelColor(190, pixels.Color(R, G, B));
  pixels.setPixelColor(191, pixels.Color(R, G, B));
  pixels.setPixelColor(192, pixels.Color(R, G, B));
  pixels.setPixelColor(193, pixels.Color(R, G, B));
  pixels.setPixelColor(194, pixels.Color(R, G, B));
  pixels.setPixelColor(195, pixels.Color(R, G, B));
  pixels.setPixelColor(196, pixels.Color(R, G, B));
  pixels.setPixelColor(197, pixels.Color(R, G, B));
  pixels.setPixelColor(198, pixels.Color(R, G, B));
  pixels.setPixelColor(199, pixels.Color(R, G, B));
  pixels.setPixelColor(200, pixels.Color(R, G, B));
  pixels.setPixelColor(201, pixels.Color(R, G, B));
  pixels.setPixelColor(202, pixels.Color(R, G, B));
  pixels.setPixelColor(203, pixels.Color(R, G, B));
  pixels.setPixelColor(204, pixels.Color(R, G, B));
  pixels.setPixelColor(205, pixels.Color(R, G, B));
  pixels.setPixelColor(206, pixels.Color(R, G, B));
  pixels.setPixelColor(207, pixels.Color(R, G, B));
  pixels.setPixelColor(208, pixels.Color(R, G, B));
  pixels.setPixelColor(209, pixels.Color(R, G, B));
  pixels.setPixelColor(210, pixels.Color(R, G, B));
  pixels.setPixelColor(211, pixels.Color(R, G, B));
  pixels.setPixelColor(212, pixels.Color(R, G, B));
  pixels.setPixelColor(213, pixels.Color(R, G, B));
  pixels.setPixelColor(214, pixels.Color(R, G, B));
  pixels.setPixelColor(215, pixels.Color(R, G, B));
  pixels.setPixelColor(216, pixels.Color(R, G, B));
  pixels.setPixelColor(217, pixels.Color(R, G, B));
  pixels.setPixelColor(218, pixels.Color(R, G, B));
  pixels.setPixelColor(219, pixels.Color(R, G, B));
  pixels.setPixelColor(220, pixels.Color(R, G, B));
  pixels.setPixelColor(221, pixels.Color(R, G, B));
  pixels.setPixelColor(222, pixels.Color(R, G, B));
  pixels.setPixelColor(223, pixels.Color(R, G, B));
  pixels.setPixelColor(224, pixels.Color(R, G, B));
  pixels.setPixelColor(225, pixels.Color(R, G, B));
  pixels.setPixelColor(226, pixels.Color(R, G, B));
  pixels.setPixelColor(227, pixels.Color(R, G, B));
  pixels.setPixelColor(228, pixels.Color(R, G, B));
  pixels.setPixelColor(229, pixels.Color(R, G, B));
  pixels.setPixelColor(230, pixels.Color(R, G, B));
  pixels.setPixelColor(231, pixels.Color(R, G, B));
  pixels.setPixelColor(232, pixels.Color(R, G, B));
  pixels.setPixelColor(233, pixels.Color(R, G, B));
  pixels.setPixelColor(234, pixels.Color(R, G, B));
  pixels.setPixelColor(235, pixels.Color(R, G, B));
  pixels.setPixelColor(236, pixels.Color(R, G, B));
  pixels.setPixelColor(237, pixels.Color(R, G, B));
  pixels.setPixelColor(238, pixels.Color(R, G, B));
  pixels.setPixelColor(239, pixels.Color(R, G, B));
  pixels.setPixelColor(240, pixels.Color(R, G, B));
  pixels.setPixelColor(241, pixels.Color(R, G, B));
  pixels.setPixelColor(242, pixels.Color(R, G, B));
  pixels.setPixelColor(243, pixels.Color(R, G, B));
  pixels.setPixelColor(244, pixels.Color(R, G, B));
  pixels.setPixelColor(245, pixels.Color(R, G, B));
  pixels.setPixelColor(246, pixels.Color(R, G, B));
  pixels.setPixelColor(247, pixels.Color(R, G, B));
  pixels.setPixelColor(248, pixels.Color(R, G, B));
  pixels.setPixelColor(249, pixels.Color(R, G, B));
  pixels.setPixelColor(250, pixels.Color(R, G, B));
  pixels.setPixelColor(251, pixels.Color(R, G, B));
  pixels.setPixelColor(252, pixels.Color(R, G, B));
  pixels.setPixelColor(253, pixels.Color(R, G, B));
  pixels.setPixelColor(254, pixels.Color(R, G, B));
  pixels.setPixelColor(255, pixels.Color(R, G, B));
  pixels.show();
}
