#!/bin/bash

_ntconnect_autocomplete() {
    local cur prev
    cur=${COMP_WORDS[COMP_CWORD]}    # Current word being typed
    prev=${COMP_WORDS[COMP_CWORD-1]} # Previous word

    # Get wireless interfaces dynamically using 'ip a'
    wifi_interfaces=$(ip a | awk -F': ' '/^[0-9]+: w/{print $2}')
    all_interfaces=$(ip a | awk -F': ' '/^[0-9]+: /{print $2}')

    case "$prev" in
        -w)
            COMPREPLY=( $(compgen -W "$wifi_interfaces" -- "$cur") )
            ;;
        *)
            COMPREPLY=( $(compgen -W "-s -p -w -m -H -l -h --help" -- "$cur") )
            ;;
    esac
}

complete -F _ntconnect_autocomplete ntconnect
