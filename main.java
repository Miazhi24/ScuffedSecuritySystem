SerialPort serialPort = new SerialPort("/dev/ttyACM0");
serialPort.openPort();
serialPort.setParams(4800, 8, 1,0)
while(true){
    byte[] buffer = serialPort.readBytes(10);
    if(buffer != null){
        for(byte b:buffer){
            System.out.print(b);
        }
    }
}