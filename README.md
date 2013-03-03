cpp_anon_callback
=================

A method to implement anonymous callbacks in C++. Using static_cast and variable argument list.

What?
-----

The demo is based on a sterotypical client-server model. 
Where the Client and the Server talk to each other like Romeo and Juliet.

The Client initiates all the communicaton, with Server replying with some information.

The Client implements callbacks to handle the async calls made by the Server.

The Server knows nothing about who's listening to its messages, or who is calling its methods.
That's where the Anonymous words comes in.

Though there is a fixed protcol, that has to be obeyed by both parties.

The Message Passing is handled by Interface Callback (ICB) class, and the family.
Where each specific child implements a specific protocol.

Where?
------

I'm using this in my Hideous Game Engine. I have a Screen class that holds references to all the Entities.

The Entities have no idea about their Screen class.

For example, the Weapon class blindly sends start and end points, whenever it fires a bullet. 
In hope that someone could be implementing the method like:

```cpp
void doCollisionCheck(vec2 start, vec2 end){
// Collision detection here
}
```


Next?
-----

This code is strictly just a demo. Non-optimized. Not production standard.

I assume you add more error checkings and optimiztion in your code as needed.

Hope this comes to help to somebody else also. :D

Cheers!
