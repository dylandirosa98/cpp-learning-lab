{
  description = "C++ Learning Lab development environment";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          python3
          gcc
          cmake
          git
          gh
        ];

        shellHook = ''
          echo "C++ Learning Lab: Python $(python3 --version | cut -d' ' -f2), GCC $(g++ -dumpversion)"
        '';
      };
    };
}
