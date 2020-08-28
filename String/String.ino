void setup() {
  Serial.begin(115200);
  //add
  String a = "123456789";
  String b = a + " " + "0";

  //cut
  String c = b.substring(5);
  String d = b.substring(0,9);


  //split
  String split = "Username,Password";
  String word3 = getValue(split, ',', 0);
  String word2 = getValue(split, ',', 1);
  Serial.println(word3);
  Serial.println(word2);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}


String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
