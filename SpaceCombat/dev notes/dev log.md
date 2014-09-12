## Space Combat dev log
---

#### 09/12/2014

4:00AM
~~~
* Just created the Game class. Doing some formatting and implementation of the main methods that comprise it.
* Got to admit, I'm not happy to be using SDL 1.2, the API feels old while using it and getting official documentation is hard.
* Finally found the official docs: http://www.libsdl.org/release/SDL-1.2.15/docs/html/sdlsetvideomode.html. Google kept taking me to the SDL 2.0 wiki.

5:11AM
~~~
* Made a commit with the new Game class being used from main. Things are starting to roll on...
* Started implementing an abstraction of the SDL Event class. This will help me override the input functions I might want to use in the future.
  I should wait until I start with the input part, but I wan't to get it out of the way ASAP. Not sure if the implementation of SDL 2.0 will work.

5:43AM
~~~
* Done with the implementation of my SDL Event class wrapper. Now the game handles events just the way I want.
* I'll try to go for the stretch and implement the touch event support.

6:11AM
~~~
* Even though I implemented the touch methods to the SDL wrapper I had to add an #IF macro to the event type check.
  It turns out that the SDL lib I'm linking against is 1.2 which doesn't have touch support. I added some code to jump into emscripten to test them
  but I'm having some issues with the 'emscripten_set_main_loop' call. I already changed my OnExecute to return 'void' but still it doesn't work.
  I'm tired and I'm gonna call it a night. Maybe in a couple hours I can find out what's happening.
