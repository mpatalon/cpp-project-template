FROM gcc:15-trixie

LABEL maintainer="mpatalon"
LABEL description="C++ development container with GCC"

SHELL ["/bin/bash", "-o", "pipefail", "-c"]

ARG USERNAME=developer
ARG HOME=/home/developer
ARG DOCKER_VOLUME=/home/developer/volume

ENV USERNAME=${USERNAME}
ENV HOME=${HOME}
ENV DOCKER_VOLUME=${DOCKER_VOLUME}

ENV USER_UID=1000
ENV USER_GID=${USER_UID}

ENV TZ=Europe/Warsaw

RUN export DEBIAN_FRONTEND=noninteractive \
  && export APT_KEY_DONT_WARN_ON_DANGEROUS_USAGE=DontWarn \
  && apt-get update \
  && apt-get -y install \
    apt-utils \
    build-essential \
    ccache \
    clang-format \
    clang-tidy \
    cmake \
    cppcheck \
    curl \
    file \
    gdb \
    git \
    jq \
    lcov \
    ninja-build \
    pkg-config \
    sudo \
    valgrind \
    vim \
  && apt-get autoremove -y \
  && apt-get clean -y \
  && rm -rf /var/lib/apt/lists/*

RUN \
  groupadd --gid ${USER_GID} ${USERNAME} \
  && useradd --uid ${USER_UID} --gid ${USERNAME} --shell /bin/bash --create-home ${USERNAME} \
  && usermod -aG sudo ${USERNAME} \
  && echo ${USERNAME} ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} \
  && chmod 0440 /etc/sudoers.d/${USERNAME}

ENV PROMPT_COMMAND='history -a'

RUN \
  mkdir -p \
    ${DOCKER_VOLUME} \
    ${DOCKER_VOLUME}/.vscode-server/extensions \
    ${DOCKER_VOLUME}/.vscode-server-insiders/extensions \
  && touch ${DOCKER_VOLUME}/.bash_history \
  && ln -s ${DOCKER_VOLUME}/.bash_history ${HOME}/.bash_history \
  && ln -s ${DOCKER_VOLUME}/.vscode-server ${HOME}/.vscode-server \
  && ln -s ${DOCKER_VOLUME}/.vscode-server-insiders ${HOME}/.vscode-server-insiders \
  && chown -R ${USERNAME}:${USERNAME} ${HOME}

WORKDIR ${HOME}
USER ${USERNAME}
