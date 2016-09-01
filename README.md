# objectify

c++ base classes for scene graph elements

#### example from unit test
```
Context c;
mover m( c );
    
c = time_slice<double>(1.9); // m will be notified (dynamic_base)
c = frame_swap<void>(); // m will be notified (visual_base)
c = event_info<void>(6, receiver::id_key_down ); // m will be notified (receiver_base)
```
