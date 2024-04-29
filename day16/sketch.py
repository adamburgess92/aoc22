m = {
    "AA": {
        "flow_rate":0,
        "tunnels":["DD", "II", "BB"]
    },
    "BB": {
        "flow_rate":13,
        "tunnels":["CC", "AA"]
    },
    "CC": {
        "flow_rate":2,
        "tunnels" : ["DD", "BB"]
    },
    "DD": {
        "flow_rate":20,
        "tunnels":["CC", "AA", "EE"]
    },
    "EE": {
        "flow_rate":3,
        "tunnels": ["FF", "DD"]
    },
    "FF": {
        "flow_rate":0,
        "tunnels": ["EE", "GG"]
    },
    "GG": {
        "flow_rate":0,
        "tunnels" : ["FF", "HH"]
    },
    "HH": {
        "flow_rate":22, 
        "tunnel" : ["GG"]
    },
    "II": {
        "flow_rate":0, 
        "tunnels":["AA", "JJ"]
    },
    "JJ": {
        "flow_rate":21, 
        "tunnel" : ["II"]
    }
}
