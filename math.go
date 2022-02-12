// Me messing around with the electrical ratings of various componenets to easily answer questions
// for myself while learning about circuit programming.
// Watts is the unit of measure for power
// Power is the speed/rate at which electrical energy is transferred in a circuit.
// Watts is represented by "P" in equations.
watts = 1
// Ampere (amp) is the unit of measure for current.
// Current is the speed/rate that electrons flow through a conductor.
// Current is represented by the letter "I" (eye) in equations.
// SPEED THE WATER FLOWS THROUGH THE HOSE
amps = 1
// Ohms measure resistance in a conductor.
// Resistance tries to slow the flow of electrons. 
// Ohms are represented by "R" in electrical equations.
// HOW WIDE THE HOSE IS
ohms = 1
// Voltage (volts) is the unit of measure for electrical potential.
// This is the number of electrons between two points in a circuit.
// Voltage is represented by the letter "V" (vee) in equations.
// PRESSURE THAT PUSHES WATER THROUGH THE HOSE
var volts = 1
var I = amps
var R = ohms
// Voltage equals Current * Resistance
// Voltage equals amps    * ohms
var V = I * R
// Watts equals volts * current
var P = V * I
//////////////////////////////////////////////
// Voltage dictates the ultimate speed of the vehicle
// kV means RPM per Volt...
// kV/RPM = Volts
// kV/Volts = RPM
//////////////////////////////////////////////

type Battery struct{
	Voltage = 11.1 // 
	Capacity = 5000 // drain I can put on the battery to discharge it in an hour
	cell_size = 3.7 // cell_size * cell_count = 11.1 Voltage when wired in series
	cell_count = 3 //
	Length = 139 // millimeters
	Width = 46 //
	Height = 39 //
	MaxContinDisch = 30 // 
	MacBusrtDisch = MaxContinDisch + 0  //
	Weight = 410 // grams
}


// Servo Torque: 21.5kg/cm @ 6.8v, weighs 60 grams
// L298N up to 12v, also a 5v


// Spektrum RC 3S Smart LiPo Hard Case Battery Pack w/IC3 Connector (11.1V/5000mAh). 30C max continuous discharge
// 3.7v Cell size x 3
Battery = {"Capacity": 5000}

current_charge = Battery.Capacity

fmt.print(current_charge)
