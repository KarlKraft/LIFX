//
//  LIFXPacket.h
//  LIFX
//
//  Created by Karl Kraft on 7/6/22.
//  Copyright 2022-2023 Karl Kraft. Licensed under Apache License, Version 2.0.
//

@import AppKit;

@class UDPSocket;



typedef NS_ENUM(int, PacketType) {
  // Device
  GetService=2,
  StateService=3,
  GetHostFirmware=14,
  StateHostFirmware=15,
  GetWifiInfo=16,
  StateWifiInfo=17,
  GetWifiFirmware=18,
  StateWifiFirmware=19,
  GetPower=20,
  SetPower=21,
  StatePower=22,
  GetLabel=23,
  SetLabel=24,
  StateLabel=25,
  GetVersion=32,
  StateVersion=33,
  GetInfo=34,
  StateInfo=35,
  SetReboot=38,
  Acknowledgement=45,
  GetLocation=48,
  SetLocation=49,
  StateLocation=50,
  GetGroup=51,
  SetGroup=52,
  StateGroup=53,
  EchoRequest=58,
  EchoResponse=59,
  //Light
  GetColor=101,
  SetColor=102,
  SetWaveform=103,
  LightState=107,
  GetLightPower=116,
  SetLightPower=117,
  StateLightPower=118,
  SetWaveformOptional=119,
  GetInfrared=120,
  StateInfrared=121,
  SetInfrared=122,
  GetHevCycle=142,
  SetHevCycle=143,
  StateHevCycle=144,
  GetHevCycleConfiguration=145,
  SetHevCycleConfiguration=146,
  StateHevCycleConfiguration=147,
  GetLastHevCycleResult=148,
  StateLastHevCycleResult=149,
  StateUnhandled=223,
  // mutlizone
  SetColorZones=501,
  GetColorZones=502,
  StateZone=503,
  StateMultiZone=506,
  GetMultiZoneEffect=507,
  SetMultiZoneEffect=508,
  StateMultiZoneEffect=509,
  SetExtendedColorZones=510,
  GetExtendedColorZones=511,
  StateExtendedColorZones=512,
  // Relay
  GetRPower=816,
  SetRPower=817,
  StateRPower=818,
  // Tile
  GetDeviceChain=701,
  StateDeviceChain=702,
  SetUserPosition=703,
  Get64=707,
  State64=711,
  Set64=715,
  GetTileEffect=718,
  SetTileEffect=719,
  StateTileEffect=720,
};

@interface LIFXPacket : NSObject

- (PacketType)packetType;
+ (LIFXPacket *)readFromSocket:(UDPSocket *)socket;
+(LIFXPacket *)getServicePacket;
+(LIFXPacket *)powerOffPacket;
+(LIFXPacket *)powerOnPacket;
+(LIFXPacket *)getPowerPacket;
- (void)send:(UDPSocket *)socket;
+(LIFXPacket *)setColor:(NSColor *)c;
- (double)powerLevel;

@end

