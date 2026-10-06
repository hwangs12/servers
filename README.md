What do I want to do?

I think my app should:

    1. It serves many people
    2. It is something that people need
    3. Not overly complicated
    4. Multithreaded

Some ideas:

    1. File download server
    2. Streaming
    3. Video chat

# FILE DOWNLOAD SERVER

    - it is a server that lets you download a file
    - easy to scale I think because people don't dwell on server much and real memory is coming from my storage (ideally)
    - I am currently stuck at making this multhread
    - first i need to set up server itself
    - then make those listeners in different cores to respond
    - once downloads start let other thread serve customer request
