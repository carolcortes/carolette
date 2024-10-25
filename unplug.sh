#!/bin/sh

ALIAS_COMMAND="alias carolette='sh ~/carolette/carolette.sh'"

remove_alias() {
    local file="$1"
    if [ -f "$file" ]; then
        # Check if alias exists before trying to remove it
        if grep -q "$ALIAS_COMMAND" "$file"; then
            # Remove the alias line
            sed -i "\|$ALIAS_COMMAND|d" "$file"
            echo "Alias removed from $file."
        fi
    fi
}

# Remove alias from .bashrc
remove_alias ~/.bashrc

# Remove alias from .zshrc
remove_alias ~/.zshrc
