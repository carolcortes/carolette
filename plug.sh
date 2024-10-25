#!/bin/sh

ALIAS_COMMAND="alias carolette='sh ~/carolette/carolette.sh'"

add_alias() {
    local file="$1"
    if [ -f "$file" ]; then
        # Check if alias already exists to avoid duplication
        if ! grep -q "alias carolette=" "$file"; then
            echo $ALIAS_COMMAND >> "$file"
            echo "Alias added to $file."
        fi
    fi
}

# Add alias to .bashrc
add_alias ~/.bashrc

# Add alias to .zshrc
add_alias ~/.zshrc
