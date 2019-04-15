/* Lift
 * Author: Ruslan Sakevych
 * Creation date: 4/14/2019
 */
MACHINE
    Lift
SETS
    DOORS_STATE     = {OPEN, CLOSE};
    MOVE_STATE      = {UP, DOWN, STOP};
    BUTTON_STATE    = {BUTTON_UP, NONE, BUTTON_DOWN};
    OCCUPANCY_STATE = {FREE, FULL};
    EMERGENCY_STATE = {YES, NO}
 
VARIABLES
    DoorsState,
    MoveState,
    ButtonState,
    OccupancyState,
    EmergencyState
   
INVARIANT
    DoorsState     : DOORS_STATE &
    MoveState      : MOVE_STATE &
    ButtonState    : BUTTON_STATE &
    OccupancyState : OCCUPANCY_STATE &
    EmergencyState : EMERGENCY_STATE &
   
    ((DoorsState = OPEN) => (MoveState = STOP)) &
    ((MoveState = STOP) => (ButtonState = NONE)) &
    ((EmergencyState = YES) => (DoorsState = OPEN)) &
    (((OccupancyState = FULL) & (DoorsState = CLOSE)) => (MoveState /= STOP))
   
INITIALISATION
    DoorsState     := CLOSE ||
    MoveState      := STOP  ||
    ButtonState    := NONE  ||
    OccupancyState := FREE  ||
    EmergencyState := NO
 
OPERATIONS
    Lift_arrive = PRE
        MoveState = DOWN & DoorsState = CLOSE
    THEN
        MoveState   := STOP ||
        DoorsState  := OPEN ||
        ButtonState := NONE
    END;
    Lift_call_free_lift_up = PRE
        MoveState = STOP & OccupancyState = FREE & ButtonState = BUTTON_UP & DoorsState = CLOSE
    THEN
        MoveState := UP
    END;
    Lift_call_free_lift_down = PRE
        MoveState = STOP & OccupancyState = FREE & ButtonState = BUTTON_DOWN & DoorsState = CLOSE
    THEN
        MoveState := DOWN
    END;
    Lift_emergency = PRE
        EmergencyState = NO
    THEN
        EmergencyState := YES  ||
        MoveState      := STOP ||
        DoorsState     := OPEN ||
        ButtonState    := NONE
    END
END
