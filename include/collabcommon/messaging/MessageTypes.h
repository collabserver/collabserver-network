#pragma once

namespace collab {


/**
 * List all possible messages.
 */
enum class MessageTypes : int {
    // Start at 1 because 0 was doing weird behavior with bit-backing types.


    // Internal use (TO KEEP LAST): has the total number of defined messages
    COUNTER
};


} // End namespace


